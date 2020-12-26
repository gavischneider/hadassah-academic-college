(() => {
  window.addEventListener("DOMContentLoaded", () => {
    document
      .getElementById("submitButton")
      .addEventListener("click", handleSubmit);
    document.getElementById("warningMessage").style.display = "none";
  });
})();

// When the user clicked submit
function handleSubmit() {
  removeErrorsFromDOM();
  let email = document.getElementById("emailInput").value.trim();
  let firstName = document.getElementById("firstNameInput").value.trim();
  let lastName = document.getElementById("lastNameInput").value.trim();

  console.log(`email: ${email}`);
  console.log(`first name: ${firstName}`);
  console.log(`last name: ${lastName}`);

  let errors = validateForm(email, firstName, lastName);
  if (errors.length > 0) {
    displayErrors(errors);
  } else {
    // If we get here, there are no errors, send data to server for validation
    //.....
    window.location.replace("http://localhost:3000/auth/password");
  }
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
function validateForm(email, firstName, lastName) {
  // Validate
  let errors = [];

  if (email === "") {
    errors.push("Email is missing");
  }
  if (!firstName) {
    errors.push("First name is missing");
  }
  if (!lastName) {
    errors.push("Last name is missing");
  }

  if (firstName && validName(firstName)) {
    errors.push("First name may not contain numbers");
  }

  if (lastName && validName(lastName)) {
    errors.push("Last name may not contain numbers");
  }

  if (!validEmail(email)) {
    errors.push("Please enter a valid email address");
  }

  return errors;
}

// Validate names
function validName(name) {
  const numbersRegex = /\d/g;
  return numbersRegex.test(name);
}

// Validate email
function validEmail(email) {
  const emailRegex = /^(([^<>()\[\]\\.,;:\s@"]+(\.[^<>()\[\]\\.,;:\s@"]+)*)|(".+"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/;
  return emailRegex.test(email);
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
