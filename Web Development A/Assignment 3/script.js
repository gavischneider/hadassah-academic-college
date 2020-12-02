window.addEventListener("DOMContentLoaded", () => {
  document.getElementById("warningMessage").style.display = "none";
  document
    .getElementById("submitButton")
    .addEventListener("click", handleSubmit);
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
    addNewLocationToList(name, latitude, longitude);
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
  button.textContent = "Remove";
  location.textContent = `${name}: Latitude: ${latitude}, Longitude: ${longitude}`;
  location.appendChild(button);

  locationList.appendChild(location);
}
