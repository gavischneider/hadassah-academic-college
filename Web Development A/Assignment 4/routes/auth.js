const express = require("express");
const router = express.Router();
const User = require("../models").User;
const Location = require("../models").Location;
const authController = require("../controllers/authControllers");
const userIsAuthenticated = require("../public/javascripts/userIsAuthenticated");

// Home route (Auth)
router.get("/", (req, res, next) => {
  res.send("Auth routes");
});

// Register route
router.get("/register", (req, res) => {
  res.render("register", { title: "The Weather App" });
});

// Password route
router.get("/password", (req, res) => {
  if (userIsAuthenticated(req.session)) {
    res.render("password", { title: "The Weather App" });
  } else {
    return res.redirect("login");
  }
});

// Login route
router.get("/login", (req, res) => {
  res.render("login", { title: "The Weather App", message: "" });
});
router.post("/login", authController.login);

// Lookup route
router.post("/lookup", authController.lookup);

// Create new user
router.post("/password", authController.password);

// Logout route
router.get("/logout", authController.logout);

module.exports = router;
