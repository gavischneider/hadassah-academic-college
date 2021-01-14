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
        console.log("Heres the user - after lookup: ");
        console.log(user);
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
        res.send(err);
      });
  },

  login(req, res) {
    const email = req.body.email;
    const password = req.body.password;
    User.findOne({
      where: { email, password },
    })
      .then(async (user) => {
        console.log("*USER*");
        console.log(user);

        if (user) {
          console.log("Success");
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

          const newUser = {
            id,
            firstName,
            lastName,
            email,
            locations: Array.from(locations),
          };

          req.session.user = newUser;

          console.log("Login success, redirecting to index");
          return res.redirect("/");
        } else {
          console.log("Failure");

          // We could not find a user with that email/password
          res.render("login", { title: "login", message: "Error logging in" });
        }
      })
      .catch((err) => {
        console.log(`Error while searching for user: ${err}`);
      });
  },

  logout(req, res) {
    console.log("LOGOUT CONTROLLER");
    //req.logOut();
    req.session.destroy(function (err) {
      req.session = null;
      if (err) {
        console.log(err);
      } else {
        //res.redirect(200, "login", { title: "login", message: "login-message" });
        return res.redirect("/");
        //res.render("login", { title: "login", message: "Some Message" });
      }
    });
  },
};

module.exports = authController;
