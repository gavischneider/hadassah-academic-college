const express = require("express");
const router = express.Router();
const User = require("../models").User;
const Location = require("../models").Location;

router.get("/", (req, res, next) => {
  res.send("Location routes");
});

router.post("/add", (req, res, next) => {
  const name = req.body.name;
  const latitude = req.body.latitude;
  const longitude = req.body.longitude;
  const userId = req.session.user.dataValues.id;

  Location.create({
    name: name,
    lat: latitude,
    lon: longitude,
    userId: userId,
  })
    .then((res) => {
      // Store the user in the session
      let newUser = {
        ...req.session.user,
        locations: [
          ...req.session.user.locations,
          { name, lat: latitude, lon: longitude },
        ],
      };

      req.session.user = newUser;
      res.send(res);
    })
    .catch((err) => {
      res.send(err);
    });
});

module.exports = router;
