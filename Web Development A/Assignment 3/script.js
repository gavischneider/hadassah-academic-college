window.addEventListener("DOMContentLoaded", () => {
  document.getElementById("warningMessage").style.display = "none";
  document
    .getElementById("submitButton")
    .addEventListener("click", handleSubmit);
});

function handleSubmit() {
  let errors = validateForm();
  if (errors.length > 0) {
    displayErrors(errors);
  }
}

function validateForm() {
  // Validate
  let errors = [];
  let name = document.getElementById("nameInput").value.trim();
  let latitude = document.getElementById("latitudeInput").value.trim();
  let longitude = document.getElementById("longitudeInput").value.trim();

  if (!name) {
    errors.push("First name is missing");
  }
  if (!latitude) {
    errors.push("Latitude name is missing");
  }
  if (!longitude) {
    errors.push("Longitude name is missing");
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
