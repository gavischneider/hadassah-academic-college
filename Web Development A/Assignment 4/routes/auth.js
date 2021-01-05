const express = require("express");
const router = express.Router();
const User = require("../models").User;

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
      res.send(res);
    })
    .catch((err) => {
      res.send(err);
    });
});

// Login route
router.get("/login", (req, res) => {
  res.render("login", {
    title: "login",
    message: "You have successfully registered. Please login:",
  });
});

// Get all users
router.get("/getusers", (req, res) => {
  User.findAll().then((userData) => {
    res.json(userData);
  });
});

module.exports = router;
