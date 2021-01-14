const express = require("express");
const router = express.Router();
const User = require("../models").User;
const Location = require("../models").Location;
const locationsController = require("../controllers/locationsControllers");

// Home route (locations)
router.get("/", (req, res, next) => {
  res.send("Location routes");
});

// Add location route
router.post("/add", locationsController.add);

// Remove location route
router.post("/remove", locationsController.remove);

// Remove all locations route
router.post("/removeall", locationsController.removeAll);

// Load locations route
router.get("/load", locationsController.loadUsersLocations);

module.exports = router;
