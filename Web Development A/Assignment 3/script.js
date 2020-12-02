window.addEventListener("DOMContentLoaded", () => {
  document.getElementById("imageContainer").style.display = "none";
  document.getElementById("warningMessage").style.display = "none";
  document
    .getElementById("submitButton")
    .addEventListener("click", handleSubmit);
  document
    .getElementById("showWeatherButton")
    .addEventListener("click", fetchWeather);
});

function handleSubmit() {
  removeErrorsFromDOM();

  let name = document.getElementById("nameInput").value.trim();
  let latitude = document.getElementById("latitudeInput").value.trim();
  let longitude = document.getElementById("longitudeInput").value.trim();

  let errors = validateForm(name, latitude, longitude);
  if (errors.length > 0) {
    displayErrors(errors);
  } else {
    // If we get here, there are no errors, add the new location to list
    document.getElementById("message").style.display = "none";
    addNewLocationToList(name, latitude, longitude);
    cleanInputs();
  }
}

function removeErrorsFromDOM() {
  warningMessage = document.getElementById("warningMessage").style.display =
    "none";
  let listOfErrors = document.getElementById("list-of-errors");
  if (listOfErrors) {
    listOfErrors.parentElement.removeChild(listOfErrors);
  }
}

function validateForm(name, latitude, longitude) {
  // Validate
  let errors = [];

  if (!name) {
    errors.push("First name is missing");
  }
  if (!latitude) {
    errors.push("Latitude is missing");
  }
  if (!longitude) {
    errors.push("Longitude is missing");
  }
  if (isNaN(latitude)) {
    errors.push("Latitude must be a number");
  }
  if (isNaN(longitude)) {
    errors.push("longitude must be a number");
  }
  return errors;
}

function displayErrors(errors) {
  listOfErrors = document.createElement("ul");
  listOfErrors.setAttribute("id", "list-of-errors");
  errors.map((error) => {
    newError = document.createElement("li");
    newError.textContent = error;
    listOfErrors.appendChild(newError);
  });
  let warningMessage = document.getElementById("warningMessage");
  warningMessage.appendChild(listOfErrors);
  warningMessage.style.display = "block";
}

function addNewLocationToList(name, latitude, longitude) {
  let locationList = document.getElementById("list-tab");
  let location = document.createElement("div");
  location.classList.add("locationItem");
  location.classList.add("list-group-item");
  location.classList.add("list-group-item-action");
  location.classList.add("d-flex");
  location.classList.add("align-items-center");
  location.classList.add("justify-content-between");
  location.setAttribute("data-toggle", "list");
  location.setAttribute("role", "tab");
  let button = document.createElement("button");
  button.setAttribute("type", "button");
  button.classList.add("btn");
  button.classList.add("btn-danger");
  button.addEventListener("click", removeLocation);
  button.textContent = "Remove";
  location.textContent = `${name}: Latitude: ${latitude}, Longitude: ${longitude}`;
  location.setAttribute("latitude", latitude);
  location.setAttribute("longitude", longitude);
  location.appendChild(button);
  locationList.appendChild(location);
}

function removeLocation(event) {
  event.target.parentElement.parentElement.removeChild(
    event.target.parentElement
  );
}

function cleanInputs() {
  document.getElementById("nameInput").value = "";
  document.getElementById("latitudeInput").value = "";
  document.getElementById("longitudeInput").value = "";
}

async function fetchWeather() {
  // Check if a list item is 'active'
  let locationItems = Array.from(document.querySelectorAll(".locationItem"));
  if (locationItems.length > 0) {
    let activeItem = locationItems.filter((location) => {
      return location.classList.contains("active");
    });
    if (activeItem) {
      // fix this
      // We found an 'active' item
      const latitude = activeItem[0].attributes.latitude.nodeValue;
      const longitude = activeItem[0].attributes.longitude.nodeValue;
      try {
        const weather = await getWeather(latitude, longitude);
        const weatherJson = await weather.json();
        console.log("-----WEATHER-----");
        console.log(weatherJson);
        console.log("-----------------");
        console.log(JSON.stringify(weatherJson));

        // Build the image url and place it in the DOM
        let imageURL = `http://www.7timer.info/bin/astro.php?lon=${longitude}&amp;lat=${latitude}&amp;ac=0&amp;lang=en&amp;unit=metric&amp;output=internal&amp;tzshift=0`;
        document.getElementById("weatherImage").setAttribute("src", imageURL);
        document.getElementById("imageContainer").style.display = "block";
      } catch (error) {
        console.log(console.error());
      }
    }
  }
}

async function getWeather(latitude, longitude) {
  let response = await fetch(
    "http://www.7timer.info/bin/api.pl?" +
      new URLSearchParams({
        lon: longitude,
        lat: latitude,
        product: "civillight",
        output: "json",
      })
  );
  return response;
}
// http://www.7timer.info/bin/api.pl?lon=35.213618&amp;lat=31.771959&amp;product=civillight&amp;output=json
// lon= 35.213618
// lat= 31.771959

// pic url
// http://www.7timer.info/bin/astro.php?lon=35.213618&amp;lat=31.771959&amp;ac=0&amp;lang=en&amp;unit=metric&amp;output=internal&amp;tzshift=0
