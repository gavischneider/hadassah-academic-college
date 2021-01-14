(() => {
  window.addEventListener("DOMContentLoaded", () => {
    document.getElementById("imageContainer").style.display = "none";
    document.getElementById("warningMessage").style.display = "none";
    document
      .getElementById("submitButton")
      .addEventListener("click", handleSubmit);
    document
      .getElementById("logout-button")
      .addEventListener("click", handleLogout);
    document
      .getElementById("showWeatherButton")
      .addEventListener("click", fetchWeather);
    document
      .getElementById("remove-all-button")
      .addEventListener("click", removeAll);
    let delButtons = document.querySelectorAll(".delete-button");
    for (let i = 0; i < delButtons.length; i++) {
      delButtons[i].addEventListener("click", removeLocation);
    }
  });

  // Data structure to hold locations
  let locations = [];

  // When the user submits a new location
  function handleSubmit() {
    console.log("Handle submit - new locations");
    removeErrorsFromDOM();

    let name = document.getElementById("nameInput").value.trim();
    let latitude = document.getElementById("latitudeInput").value.trim();
    let longitude = document.getElementById("longitudeInput").value.trim();

    let errors = validateForm(name, latitude, longitude);
    if (errors.length > 0) {
      displayErrors(errors);
    } else {
      // If we get here, there are no errors, add the new location to list
      //document.getElementById("message").style.display = "none";
      addNewLocationToList(name, latitude, longitude);
      cleanInputs();
    }
  }

  function handleLogout() {
    fetch("http://localhost:3000/auth/logout", {
      method: "GET",
    })
      .then(window.location.replace("http://localhost:3000/auth/login"))
      .catch((err) => {
        console.log(`Error logging user our, ${err}`);
      });
  }

  // Clean up all visible errors
  function removeErrorsFromDOM() {
    warningMessage = document.getElementById("warningMessage").style.display =
      "none";
    let listOfErrors = document.getElementById("list-of-errors");
    if (listOfErrors) {
      listOfErrors.parentElement.removeChild(listOfErrors);
    }
  }

  // Verify that everything is as expected
  function validateForm(name, latitude, longitude) {
    // Validate
    let errors = [];

    if (!name) {
      errors.push("Location name is missing");
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
      errors.push("Longitude must be a number");
    }
    if (latitude && (latitude > 90 || latitude < -90)) {
      errors.push("Latitude must be a number between +90 and -90");
    }
    if (longitude && (longitude > 180 || longitude < -180)) {
      errors.push("Longitude must be a number between +180 and -180");
    }

    // Check if location already exists
    locations.map((location) => {
      if (location.latitude === latitude && location.longitude === longitude) {
        errors.push("You have already entered these coordinates");
      }
    });
    return errors;
  }

  // Display relevant errors
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

  // Add a new location to DOM and to data structure
  function addNewLocationToList(name, latitude, longitude) {
    let locationList = document.getElementById("list-tab");

    fetch("http://localhost:3000/location/add", {
      method: "POST",
      headers: {
        Accept: "application/json",
        "Content-Type": "application/json",
        "Access-Control-Origin": "*",
      },
      body: JSON.stringify({
        name: name,
        latitude: latitude,
        longitude: longitude,
      }),
    })
      .then((res) => res.json())
      .then((data) => {
        console.log("Added new location: ");
        console.log(data);
        window.location.replace("http://localhost:3000");
      })
      .catch((err) => {
        console.log(err);
      });

    // let location = document.createElement("div");
    // location.classList.add(
    //   "locationItem",
    //   "list-group-item",
    //   "list-group-item-action",
    //   "d-flex",
    //   "align-items-center",
    //   "justify-content-between"
    // );
    // location.setAttribute("data-toggle", "list");
    // location.setAttribute("role", "tab");
    // let button = document.createElement("button");
    // button.setAttribute("type", "button");
    // button.classList.add("btn");
    // button.classList.add("btn-danger");
    // button.addEventListener("click", removeLocation); // ADD THIS
    // button.textContent = "Remove";
    // location.textContent = `${name}: Latitude: ${latitude}, Longitude: ${longitude}`;
    //0000
    //location.setAttribute("latitude", latitude);
    //location.setAttribute("longitude", longitude);
    //0000
    // location.appendChild(button);
    // locationList.appendChild(location);

    // let newLocation = {
    //   name: name,
    //   latitude: latitude,
    //   longitude: longitude,
    // };

    // locations.push(newLocation);
  }

  // When the user removes a location
  function removeLocation(event) {
    console.log("EVENT.PATH['body']");
    console.log(event.currentTarget.getAttribute("id"));

    const loactionName = event.currentTarget.getAttribute("id");

    fetch("http://localhost:3000/location/remove", {
      method: "POST",
      headers: {
        Accept: "application/json",
        "Content-Type": "application/json",
        "Access-Control-Origin": "*",
      },
      body: JSON.stringify({
        name: loactionName,
      }),
    })
      .then((data) => {
        console.log("Location removed ");
        console.log(data);
        window.location.replace("http://localhost:3000");
      })
      .catch((err) => {
        console.log(err);
      });
  }

  function removeAll() {
    // Check if there are locations on screen
    let locationItems = Array.from(document.querySelectorAll(".locationItem"));
    console.log(locationItems);
    if (locationItems.length > 0) {
      // There are, delete all of them
      fetch("http://localhost:3000/location/removeall", {
        method: "POST",
      })
        .then((data) => {
          console.log("All locations removed ");
          console.log(data);
          window.location.replace("http://localhost:3000");
        })
        .catch((err) => {
          console.log(err);
        });
    } else {
      // There are no locations, do nothing
    }
  }

  // Empty out the inputs
  function cleanInputs() {
    document.getElementById("nameInput").value = "";
    document.getElementById("latitudeInput").value = "";
    document.getElementById("longitudeInput").value = "";
  }

  // Get the weather
  async function fetchWeather() {
    console.log("~~~~~~~ Fetch Weather");
    // Check if a list item is 'active'
    let locationItems = Array.from(document.querySelectorAll(".locationItem"));
    console.log(locationItems);
    if (locationItems.length > 0) {
      let activeItem = locationItems.filter((location) => {
        return location.classList.contains("active");
      });
      if (activeItem) {
        // We found an 'active' item
        console.log("Active Item: ");
        console.log(activeItem);
        const latitude = activeItem[0].dataset.lat;
        const longitude = activeItem[0].dataset.lon;

        //console.log("LAT AND LON THAT WERE GONNA LOOK FOR: ");
        //console.log(latitude);
        //console.log(longitude);

        try {
          const weather = await getWeather(latitude, longitude);
          const weatherJson = await weather.json();

          //console.log("WEATHER JSON");
          //console.log(weatherJson);

          // Build the image url and place it in the DOM
          let imageURL = `http://www.7timer.info/bin/astro.php?lon=${longitude}&amp;lat=${latitude}&amp;ac=0&amp;lang=en&amp;unit=metric&amp;output=internal&amp;tzshift=0`;
          document.getElementById("weatherImage").setAttribute("src", imageURL);
          document.getElementById("imageContainer").style.display = "block";

          // Add today's and tommorow's weather to DOM
          let dataSeries = weatherJson.dataseries;

          console.log("DATASERIES");
          console.log(dataSeries);

          const todayWeather = dataSeries[0].weather;
          const todayTempMin = dataSeries[0].temp2m.min;
          const todayTempMax = dataSeries[0].temp2m.max;
          const todayWind = dataSeries[0].wind10m_max;
          if (todayWind == 1) {
            todayWind = "None";
          }

          //console.log("TODAYS WEATHER:");
          //console.log(todayWeather);
          //console.log(todayTempMin);
          //console.log(todayTempMax);
          //console.log(todayWind);

          const tomorrowWeather = dataSeries[1].weather;
          const tomorrowTempMin = dataSeries[1].temp2m.min;
          const tomorrowTempMax = dataSeries[1].temp2m.max;
          const tomorrowWind = dataSeries[1].wind10m_max;
          if (tomorrowWind == 1) {
            tomorrowWind = "None";
          }

          let weatherList = Array.from(
            document.querySelectorAll(".weatherList")
          );

          weatherList[1].textContent = `Weather Forecast: ${todayWeather}`;
          weatherList[2].textContent = `Temperature: Between ${todayTempMin} and ${todayTempMax} (Cel)`;
          weatherList[3].textContent = `Wind Factor: ${todayWind}`;

          weatherList[5].textContent = `Weather Forecast: ${tomorrowWeather}`;
          weatherList[6].textContent = `Temperature: Between ${tomorrowTempMin} and ${tomorrowTempMax} (Cel)`;
          weatherList[7].textContent = `Wind Factor: ${tomorrowWind}`;
        } catch (error) {
          console.log(`Error: ${error}`);
        }
      }
    }
  }

  // Fetch from API
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
    if (!response) {
      window.alert("There was an issue fetching the weather data");
    }
    return response;
  }
})();
