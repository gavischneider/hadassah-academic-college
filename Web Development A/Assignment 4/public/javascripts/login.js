(() => {
  window.addEventListener("DOMContentLoaded", () => {
    document
      .getElementById("loginButton")
      .addEventListener("click", handleSubmit);
    document.getElementById("warningMessage").style.display = "none";
  });

  // When the user clicked submit
  function handleSubmit() {
    removeErrorsFromDOM();
    let email = document.getElementById("emailInput").value.trim();
    let password = document.getElementById("passwordInput").value.trim();

    console.log(`email: ${email}`);
    console.log(`password: ${password}`);

    let errors = validateForm(email, password);
    if (errors.length > 0) {
      displayErrors(errors);
    } else {
      // If we get here, there are no errors, send data to server for validation
      //.....
      window.location.replace("http://localhost:3000");
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
  function validateForm(email, password) {
    // Validate
    let errors = [];

    if (!email) {
      errors.push("Please enter email");
    }
    if (!password) {
      errors.push("Please enter password");
    }
    if (password.length < 8) {
      errors.push("Password must be at least 8 characters");
    }

    if (!validEmail(email)) {
      errors.push("Please enter a valid email address");
    }

    return errors;
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
})();
