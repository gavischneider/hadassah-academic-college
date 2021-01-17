const bcrypt = require("bcrypt");
const saltRounds = 10;
const User = require("../models").User;
const Location = require("../models").Location;

const authController = {
  // Function to check if an email is already in use
  lookup(req, res) {
    const email = req.body.email;
    User.findOne({
      where: { email },
    })
      .then((user) => {
        if (user) {
          // Email is already in use
          res.sendStatus(403);
        } else {
          res.sendStatus(200);
        }
      })
      .catch((err) => console.log(`Error looking user up, ${err}`));
  },

  // Function to register a user (data is already validated)
  password(req, res) {
    // Create a new user
    const firstName = req.body.firstName;
    const lastName = req.body.lastName;
    const email = req.body.email;
    const password = req.body.password;

    // Hash the password before storing
    bcrypt.hash(password, saltRounds, function (err, hash) {
      if (!err) {
        User.create({
          firstName: firstName,
          lastName: lastName,
          email: email,
          password: hash,
        })
          .then((res) => {
            res.send(res);
          })
          .catch((err) => {
            res.render("register", {
              title: "The Weather App",
              message: `Error registering, ${err}`,
            });
          });
      } else {
        console.log("Error encypting password: ", err);
      }
    });
  },

  // Function to login existing users
  login(req, res) {
    const email = req.body.email;
    const password = req.body.password;
    User.findOne({
      where: { email },
    })
      .then(async (user) => {
        if (user) {
          // Compare the entered password to the stored hash
          bcrypt.compare(password, user.password, async function (err, result) {
            if (result && !err) {
              req.session.user = user;

              // We got the user, now we need to get their locations
              const locations = await Location.findAll({
                where: { userId: user.dataValues.id },
              });

              req.session.user.locations = Array.from(locations);

              const id = req.session.user.dataValues.id;
              const firstName = req.session.user.dataValues.firstName;
              const lastName = req.session.user.dataValues.lastName;
              const email = req.session.user.dataValues.email;

              // Create a new user object for the session
              const newUser = {
                id,
                firstName,
                lastName,
                email,
                locations: Array.from(locations),
              };
              req.session.user = newUser;
              return res.redirect("/");
            } else {
              res.render("login", {
                title: "The Weather App",
                message: "Error logging in, password is incorrect",
              });
            }
          });
        } else {
          // We could not find a user with that email/password
          res.render("login", {
            title: "The Weather App",
            message: "Error logging in, no registered user with that email",
          });
        }
      })
      .catch((err) => {
        res.render("login", {
          title: "The Weather App",
          message: `Error logging in, ${err}`,
        });
      });
  },

  // Function to log the user out
  logout(req, res) {
    req.session.destroy(function (err) {
      req.session = null;
      if (err) {
        console.log(err);
      } else {
        return res.redirect("/");
      }
    });
  },
};

module.exports = authController;
