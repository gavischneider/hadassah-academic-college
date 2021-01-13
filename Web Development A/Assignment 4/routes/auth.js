const express = require("express");
const router = express.Router();
const User = require("../models").User;
const Location = require("../models").Location;

/* GET users listing. */
router.get("/", (req, res, next) => {
  res.send("Auth routes");
});

// Register route
router.get("/register", (req, res) => {
  res.render("register", { title: "register" });
});

// Password route
router.get("/password", (req, res) => {
  res.render("password", { title: "password" });
});

router.get("/login", (req, res) => {
  res.render("login", { title: "login", message: "login-message" });
});

// Create new user
router.post("/password", (req, res) => {
  // console.log("-----req: =====");
  // console.log(req);
  // console.log("-----req.body: =====");
  // console.log(req.body);
  // console.log("-----req.query: =====");
  // console.log(req.query);
  // console.log("-----req.params: =====");
  // console.log(req.params);
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
      // Store the user in the session
      //req.session.user = req.body;
      // Remove password so its not in the session
      //req.session.user.dataValues.password = null;

      // const id = req.session.user.dataValues.id;
      // const firstName = req.session.user.dataValues.firstName;
      // const lastName = req.session.user.dataValues.lastName;
      // const email = req.session.user.dataValues.email;

      // const newUser = {
      //   id,
      //   firstName,
      //   lastName,
      //   email,
      //   locations: Array.from(locations),
      // };

      // req.session.user = newUser;

      res.send(res);
    })
    .catch((err) => {
      res.send(err);
    });
});

// Login route
router.post("/login", (req, res) => {
  const email = req.body.email;
  const password = req.body.password;
  User.findOne({
    where: { email, password },
  })
    .then(async (user) => {
      if (user) {
        //console.log("Success");
        //console.log(user);
        // Email and password match
        req.session.user = user;
        //console.log(user.dataValues.firstName);

        // We got the user, now we need to get their locations
        const locations = await Location.findAll({
          where: { userId: user.dataValues.id },
        });

        //locations = await locations.json();

        //console.log("LOCATIONS!");
        //console.log(locations);
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

        //console.log("req session user location");
        //console.log(req.session.user.locations);

        //console.log("REQ SESSION USERLOCATIONS LENGTH-------");
        //console.log(req.session.user.locations.length);

        //console.log("REQ SESSION USER NAME");
        //console.log(req.session.user.dataValues);

        //console.log("LOCATIONS DATAVALUES");
        //console.log(locations.dataValues);

        console.log("Login success, redirecting to index");
        return res.redirect("/"); //, {
        //   title: "Home",
        //   userName: user.firstName,
        //   locations: locations,
        // });
      } else {
        //console.log("Failure");
        //console.log(user);
        // We could not find a user with that email/password
        //res.send(null);
        res.render("login", { title: "login", message: "Error logging in" });
      }
    })
    .catch((err) => {
      console.log(`Error while searching for user: ${err}`);
    });

  // res.render("login", {
  //   title: "login",
  //   message: "You have successfully registered. Please login:",
  // });
});

// Logout route
router.get("/logout", (req, res) => {
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
});

// Get all users
router.get("/getusers", (req, res) => {
  User.findAll().then((userData) => {
    res.json(userData);
  });
});

module.exports = router;
