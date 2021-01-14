const createError = require("http-errors");
const express = require("express");
const path = require("path");
//const cookieParser = require("cookie-parser");
const logger = require("morgan");
const bodyParser = require("body-parser");
const session = require("express-session");
const { Sequelize } = require("sequelize");

const app = express();

const sequelize = new Sequelize({
  dialect: "sqlite",
  storage: "./database.sqlite3",
});

const PORT = process.env.PORT || 3000;

// view engine setup
app.set("views", path.join(__dirname, "views"));
app.set("view engine", "ejs");

app.use(bodyParser.urlencoded({ extended: false }));
app.use(bodyParser.json());
//app.use(bodyParser.json());
app.use(logger("dev"));
// app.use(express.json());
// app.use(express.urlencoded());
//app.use(cookieParser());

app.use(
  session({
    name: "appSession",
    secret: "my-secret",
    cookie: { secure: false, maxAge: 60 * 1000 * 60 }, // 1 hour
  })
);

app.use(express.static(path.join(__dirname, "public")));

const auth = require("./routes/auth");
const location = require("./routes/locations");
app.use("/auth", auth);
app.use("/location", location);

function userIsAuthenticated(session) {
  console.log("IN THE USER IS AUTH FUNCTION!");
  if (session.user) {
    console.log("Session User !!!!!!!!");
    console.log(session.user);
    return true;
  } else {
    console.log("FALSE");
    return false;
  }
}

// Home route
app.get("/", (req, res) => {
  console.log("IN THE / FUNCTION <<<<<<<<<<<<<<<<<<");
  //console.log(req.session);

  if (userIsAuthenticated(req.session)) {
    console.log("******************** BOOLEN RESPONSE ******************");
    console.log(userIsAuthenticated(req.session));

    console.log(
      "---------------------------- USER IS AUTHENTICATED ------------------------------"
    );
    res.render("index", {
      title: "The Weather App",
      userName: req.session.user.firstName || "",
      locations: req.session.user.locations || [],
    });
  } else {
    console.log("redirecting to login *****");
    return res.redirect("auth/login");
  }
});

app.get("/sessioninfo", (req, res) => {
  res.json(req.session);
});

app.get("*", (req, res) => {
  res.send("404 Page not found");
});

app.listen(PORT, () => console.log(`Server running on port ${PORT}`));
