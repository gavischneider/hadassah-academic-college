const User = require("../models").User;
const Location = require("../models").Location;

const authController = {
  // Check if an email is already in use
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

  password(req, res) {
    // Create a new user
    const firstName = req.body.firstName;
    const lastName = req.body.lastName;
    const email = req.body.email;
    const password = req.body.password;
    User.create({
      firstName: firstName,
      lastName: lastName,
      email: email,
      password: password,
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
  },

  login(req, res) {
    const email = req.body.email;
    const password = req.body.password;
    User.findOne({
      where: { email, password },
    })
      .then(async (user) => {
        if (user) {
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
          // We could not find a user with that email/password
          res.render("login", {
            title: "The Weather App",
            message: "Error logging in",
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

  // Log the user out
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
