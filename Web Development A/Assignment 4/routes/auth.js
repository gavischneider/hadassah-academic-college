const express = require("express");
const router = express.Router();
const User = require("../models/user");

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
  const firstName = req.query.firstName;
  const lastName = req.query.lastName;
  const email = req.query.email;
  const password = req.query.password;
  User.create({
    firstName,
    lastName,
    email,
    password,
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
