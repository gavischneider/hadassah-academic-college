const express = require("express");
const path = require("path");
const logger = require("morgan");
const bodyParser = require("body-parser");
const session = require("express-session");
const { Sequelize } = require("sequelize");
const SequelizeStore = require("connect-session-sequelize")(session.Store);
const auth = require("./routes/auth");
const location = require("./routes/locations");
const userIsAuthenticated = require("./public/javascripts/userIsAuthenticated");

const app = express();

// Initialize Sequelize
const sequelize = new Sequelize({
  dialect: "sqlite",
  storage: "./database.sqlite3",
});

// Initialize session store
const myStore = new SequelizeStore({
  db: sequelize,
});

const PORT = process.env.PORT || 3000;

// view engine setup
app.set("views", path.join(__dirname, "views"));
app.set("view engine", "ejs");

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());
app.use(logger("dev"));

// Configure sessions
app.use(
  session({
    name: "appSession",
    store: myStore,
    secret: "my-secret",
    cookie: { secure: false, maxAge: 60 * 1000 * 60 }, // 1 hour
  })
);

myStore.sync();

// Link public directory
app.use(express.static(path.join(__dirname, "public")));

// Routing
app.use("/auth", auth);
app.use("/location", location);

// Home route
app.get("/", (req, res) => {
  if (userIsAuthenticated(req.session)) {
    res.render("index", {
      title: "The Weather App",
      userName: req.session.user.firstName || "",
      locations: req.session.user.locations || [],
    });
  } else {
    return res.redirect("auth/login");
  }
});

app.get("/sessioninfo", (req, res) => {
  res.json(req.session);
});

// 404 Route
app.get("*", (req, res) => {
  res.render("error", {
    message: "The page does not exist",
    error: 404,
  });
});

app.listen(PORT, () => console.log(`Server running on port ${PORT}`));
