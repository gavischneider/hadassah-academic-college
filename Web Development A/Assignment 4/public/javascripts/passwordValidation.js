(() => {
  window.addEventListener("DOMContentLoaded", () => {
    document
      .getElementById("submitPasswordButton")
      .addEventListener("click", handleSubmit);
    document.getElementById("warningMessage").style.display = "none";
  });

  // When the user clicked submit
  function handleSubmit() {
    removeErrorsFromDOM();
    let password = document.getElementById("passwordInput").value.trim();
    let verifyPassword = document
      .getElementById("verifyPasswordInput")
      .value.trim();

    console.log(`password: ${password}`);
    console.log(`verify password: ${verifyPassword}`);

    let errors = validateForm(password, verifyPassword);
    if (errors.length > 0) {
      displayErrors(errors);
    } else {
      // If we get here, there are no errors, send data to server for validation
      //.....
      window.location.replace("http://localhost:3000/auth/login");
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
  function validateForm(password, verifyPassword) {
    // Validate
    let errors = [];

    if (!password) {
      errors.push("Please enter password");
    }
    if (!verifyPassword) {
      errors.push("Please verify password");
    }
    if (password.length < 8 || verifyPassword.length < 8) {
      errors.push("Password must be at least 8 characters");
    }
    if (password.localeCompare(verifyPassword) !== 0) {
      errors.push("Passwords must match");
    }

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
})();
