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

// Create new user
router.post("/password", (req, res) => {
  console.log("-----req: =====");
  console.log(req);
  console.log("-----req.body: =====");
  console.log(req.body);
  console.log("-----req.query: =====");
  console.log(req.query);
  console.log("-----req.params: =====");
  console.log(req.params);
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
      req.session.user = req.body;
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
        console.log("Success");
        console.log(user);
        // Email and password match
        req.session.user = user;
        console.log(user.dataValues.firstName);

        // We got the user, now we need to get their locations
        const locations = await Location.findAll({
          where: { userId: user.dataValues.id },
        });
        console.log("LOCATIONS!");
        console.log(locations);

        res.render("index", {
          title: "Home",
          userName: user.firstName,
          locations: locations,
        });
      } else {
        console.log("Failure");
        console.log(user);
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
  //req.logOut();
  req.session.destroy(function (err) {
    res.render("login", { title: "login", message: "login-message" });
  });
});

// Get all users
router.get("/getusers", (req, res) => {
  User.findAll().then((userData) => {
    res.json(userData);
  });
});

module.exports = router;
