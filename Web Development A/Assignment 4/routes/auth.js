const express = require("express");
const router = express.Router();
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
  res.render("password", { title: "The Weather App" });
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
