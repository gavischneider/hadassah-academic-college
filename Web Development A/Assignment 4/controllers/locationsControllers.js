const User = require("../models").User;
const Location = require("../models").Location;

const locationsController = {
  // Add a new location
  add(req, res) {
    // Check if there's a user in the session - if not, don't add location
    if (req.session.user) {
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
          // Store the new location in the session
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
    } else {
      // There's no user in the session
      res.render("login", {
        title: "The Weather App",
        message: `Error logging in, ${err}`,
      });
    }
  },

  // Remove a location
  remove(req, res) {
    const name = req.body.name;
    const userId = req.session.user.id;

    Location.destroy({
      where: { name, userId },
    })
      .then((response) => {
        // Remove the location from session
        let newLocations = req.session.user.locations.filter((loc) => {
          return loc.name.localeCompare(name) !== 0;
        });

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
  },

  // Remove all locations (for a single user)
  removeAll(req, res) {
    const userId = req.session.user.id;
    Location.destroy({
      where: { userId },
    })
      .then((response) => {
        // Remove all locations from session
        let newUser = {
          ...req.session.user,
          locations: [],
        };
        req.session.user = newUser;
        res.sendStatus(200);
      })
      .catch((err) => {
        res.send(err);
      });
  },

  // Get all of a users locations
  loadUsersLocations(req, res) {
    const userId = req.session.user.id;
    Location.findAll({
      where: { userId },
    })
      .then((locations) => {
        let locs = [];
        for (let i = 0; i < locations.length; i++) {
          let newLoc = {
            name: locations[i].dataValues.name,
            lat: locations[i].dataValues.lat,
            lon: locations[i].dataValues.lon,
          };
          locs.push(newLoc);
        }
        res.json({ locations: locs });
      })
      .catch((err) => console.log(`Error loading locations, ${err}`));
  },
};

module.exports = locationsController;
