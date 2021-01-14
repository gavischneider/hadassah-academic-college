const express = require("express");
const router = express.Router();
const User = require("../models").User;
const Location = require("../models").Location;
const authController = require("../controllers/authControllers");

/* GET users listing. */
router.get("/", (req, res, next) => {
  res.send("Auth routes");
});

// Register route
router.get("/register", (req, res) => {
  res.render("register", { title: "The Weather App" });
});

// Password route
router.get("/password", (req, res) => {
  res.render("password", { title: "The Weather App" });
});

router.get("/login", (req, res) => {
  res.render("login", { title: "The Weather App", message: "" });
});

router.post("/lookup", authController.lookup);

// Create new user
router.post("/password", authController.password);
// router.post("/password", (req, res) => {

//   const firstName = req.body.firstName;
//   const lastName = req.body.lastName;
//   const email = req.body.email;
//   const password = req.body.password;
//   User.create({
//     firstName: firstName,
//     lastName: lastName,
//     email: email,
//     password: password,
//   })
//     .then((res) => {

//       res.send(res);
//     })
//     .catch((err) => {
//       res.send(err);
//     });
// });

// Login route
router.post("/login", authController.login);
// router.post("/login", (req, res) => {
//   const email = req.body.email;
//   const password = req.body.password;
//   User.findOne({
//     where: { email, password },
//   })
//     .then(async (user) => {
//       console.log("*USER*");
//       console.log(user);

//       if (user) {
//         console.log("Success");
//         req.session.user = user;

//         // We got the user, now we need to get their locations
//         const locations = await Location.findAll({
//           where: { userId: user.dataValues.id },
//         });

//         req.session.user.locations = Array.from(locations);

//         const id = req.session.user.dataValues.id;
//         const firstName = req.session.user.dataValues.firstName;
//         const lastName = req.session.user.dataValues.lastName;
//         const email = req.session.user.dataValues.email;

//         const newUser = {
//           id,
//           firstName,
//           lastName,
//           email,
//           locations: Array.from(locations),
//         };

//         req.session.user = newUser;

//         console.log("Login success, redirecting to index");
//         return res.redirect("/");
//       } else {
//         console.log("Failure");

//         // We could not find a user with that email/password
//         res.render("login", { title: "login", message: "Error logging in" });
//       }
//     })
//     .catch((err) => {
//       console.log(`Error while searching for user: ${err}`);
//     });
// });

// Logout route
router.get("/logout", authController.logout);
// router.get("/logout", (req, res) => {
//   console.log("LOGOUT CONTROLLER");
//   //req.logOut();
//   req.session.destroy(function (err) {
//     req.session = null;
//     if (err) {
//       console.log(err);
//     } else {
//       //res.redirect(200, "login", { title: "login", message: "login-message" });
//       return res.redirect("/");
//       //res.render("login", { title: "login", message: "Some Message" });
//     }
//   });
// });

// Get all users
// router.get("/getusers", (req, res) => {
//   User.findAll().then((userData) => {
//     res.json(userData);
//   });
// });

module.exports = router;
