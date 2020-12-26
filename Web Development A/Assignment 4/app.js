const createError = require("http-errors");
const express = require("express");
const path = require("path");
const cookieParser = require("cookie-parser");
const logger = require("morgan");
const bodyParser = require("body-parser");

const app = express();

const PORT = process.env.PORT || 3000;

// view engine setup
app.set("views", path.join(__dirname, "views"));
app.set("view engine", "ejs");

app.use(bodyParser.json());
app.use(logger("dev"));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, "public")));

const auth = require("./routes/auth");
app.use("/auth", auth);

// TODO: Add first name
// Home route
app.get("/", (req, res) => {
  res.render("index", { title: "express" });
});

app.listen(PORT, () => console.log(`Server running on port ${PORT}`));
