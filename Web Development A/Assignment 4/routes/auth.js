var express = require("express");
var router = express.Router();

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

// Login route
router.get("/login", (req, res) => {
  res.render("login", {
    title: "login",
    message: "You have successfully registered. Please login:",
  });
});

module.exports = router;
