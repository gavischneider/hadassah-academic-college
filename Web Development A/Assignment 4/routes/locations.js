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
  const userId = req.session.user.id;

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

router.post("/remove", (req, res, next) => {
  console.log(" -------> /remove route");
  const name = req.body.name;
  const userId = req.session.user.id;

  Location.destroy({
    where: { name, userId },
  })
    .then((response) => {
      console.log(`Location removed from DB, ${response}`);

      // Remove the location from session
      let newLocations = req.session.user.locations.filter((loc) => {
        return loc.name.localeCompare(name) !== 0;
      });

      console.log("++++++++++++++++++ NEW LOCATIONS +++++++++++++++++++");
      console.log(newLocations);

      let newUser = {
        ...req.session.user,
        locations: [...newLocations],
      };
      req.session.user = newUser;
      res.sendStatus(200);
    })
    .catch((err) => {
      console.log(`Error removing location from DB, ${err}`);
      res.send(err);
    });
});

router.post("/removeall", (req, res, next) => {
  const userId = req.session.user.id;
  Location.destroy({
    where: { userId },
  })
    .then((response) => {
      console.log(`All locations removed, ${response}`);

      let newUser = {
        ...req.session.user,
        locations: [],
      };
      req.session.user = newUser;
      res.sendStatus(200);
    })
    .catch((err) => {
      console.log(`Error removing all locations from DB, ${err}`);
      res.send(err);
    });
});

module.exports = router;
