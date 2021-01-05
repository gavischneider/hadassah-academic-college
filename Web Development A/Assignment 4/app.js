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
app.use("/auth", auth);

function userIsAuthenticated(session) {
  if (session.user) {
    return true;
  } else {
    return false;
  }
}

// TODO: Add first name
// Home route
app.get("/", (req, res) => {
  if (userIsAuthenticated(req.session)) {
    res.render("index", { title: "express", user: req.session.user });
  } else {
    res.render("login", { title: "login", message: "login message" });
  }
});

app.get("/sessioninfo", (req, res) => {
  res.json(req.session);
});

app.listen(PORT, () => console.log(`Server running on port ${PORT}`));
