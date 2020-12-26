var express = require("express");
var router = express.Router();

/* GET users listing. */
router.get("/", (req, res, next) => {
  res.send("Auth routes");
});

// Home route
router.get("/register", (req, res) => {
  res.render("register", { title: "register" });
});

module.exports = router;
