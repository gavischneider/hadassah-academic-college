let NUM_OF_CHILDREN_DIVS = 0;

document.addEventListener("DOMContentLoaded", () => {
  document.getElementById("warning-message").style.display = "none";
  document.getElementById("button").addEventListener("click", handleSubmit);
  window.addEventListener("keyup", handleKeyUp);
});

function handleSubmit() {
  // Delete existing error messages (if they exist)
  let listOfErrors = document.getElementById("list-of-errors");
  if (listOfErrors) {
    listOfErrors.parentElement.removeChild(listOfErrors);
  }

  // Get all the inputs
  let errors = [];
  let firstName = document.getElementById("first-name-input").value.trim();
  let lastName = document.getElementById("last-name-input").value.trim();
  let birthYear = document.getElementById("birth-year-input").value.trim();
  let immigrationYear = document
    .getElementById("immigration-year-input")
    .value.trim();
  let childInputs = Array.from(document.querySelectorAll(".child-input"));

  childInputs = childInputs.map((c) => {
    return c.value.trim();
  });

  const currentYear = new Date().getFullYear();

  // Check which errors we need to display
  if (!firstName) {
    errors.push("First name is missing");
  }
  if (!lastName) {
    errors.push("Last name is missing");
  }
  if (!birthYear) {
    errors.push("Birth year is missing");
  }
  if (isNaN(birthYear)) {
    errors.push("Birth year should be a number");
  }
  if (birthYear && birthYear < 1900) {
    errors.push("Birth year should be at least 1900");
  }
  if (birthYear > currentYear) {
    errors.push("Birth year can not be after the current year");
  }
  if (!immigrationYear) {
    errors.push("Immigration year is missing");
  }
  if (isNaN(immigrationYear)) {
    errors.push("Immigration year should be a number");
  }
  if (immigrationYear && immigrationYear < 1900) {
    errors.push("Immigration year should be at least 1900");
  }
  if (immigrationYear > currentYear) {
    errors.push("Immigration year can not be after the current year");
  }
  if (immigrationYear && birthYear > immigrationYear) {
    errors.push("Immigration year should be after birth year");
  }

  // Check if a child name is missing
  let needChildError = false;
  childInputs.map((child) => {
    if (!child.value) {
      needChildError = true;
    }
    console.log("CHILD VALUE");
    console.log(child);
  });
  if (needChildError) {
    errors.push("Child name is missing");
  }

  // Check if child names are not unique
  let bool = false;
  for (i = 0; i < childInputs.length; i++) {
    for (j = 0; j < childInputs.length; j++) {
      if (i !== j) {
        if (childInputs[i].value === childInputs[j].value) {
          bool = true;
        }
      }
    }
  }
  if (bool) {
    errors.push("Child names should be different");
  }

  console.log("Variables:");
  console.log(firstName);
  console.log(lastName);
  console.log(birthYear);
  console.log(immigrationYear);

  console.log("ERRORS");
  console.log(errors);

  if (errors.length > 0) {
    listOfErrors = document.createElement("ul");
    listOfErrors.setAttribute("id", "list-of-errors");
    errors.map((error) => {
      newError = document.createElement("li");
      newError.textContent = error;
      listOfErrors.appendChild(newError);
    });
    let warningMessage = document.getElementById("warning-message");
    warningMessage.appendChild(listOfErrors);
    warningMessage.style.display = "block";
  } else {
    let warningMessage = document.getElementById("warning-message");
    warningMessage.style.display = "none";
  }
}

function handleKeyUp() {
  let numOfChildren = document.getElementById("num-of-children-input").value;

  console.log("numOfChildren / NUM_OF_CHILDREN_DIVS");
  console.log(`${numOfChildren} / ${NUM_OF_CHILDREN_DIVS}`);

  // Check if key was a number
  if (!isNaN(numOfChildren)) {
    let childrenForm = document.getElementById("children-form");
    if (numOfChildren > NUM_OF_CHILDREN_DIVS) {
      // We need more divs for children
      if (numOfChildren > 10) {
        numOfChildren = 10;
      }
      while (numOfChildren > NUM_OF_CHILDREN_DIVS) {
        let newChildDiv = document.createElement("div");
        newChildDiv.setAttribute("class", "child-div");
        let label = document.createElement("label");
        label.textContent = `Child Name ${NUM_OF_CHILDREN_DIVS + 1}: `;
        newChildDiv.appendChild(label);
        let input = document.createElement("input");
        input.setAttribute("type", "text");
        input.setAttribute("class", "form-control");
        input.setAttribute("class", "child-input");
        newChildDiv.appendChild(input);
        childrenForm.appendChild(newChildDiv);
        NUM_OF_CHILDREN_DIVS++;
      }
    }

    if (numOfChildren < NUM_OF_CHILDREN_DIVS) {
      // We need to delete children divs
      while (numOfChildren < NUM_OF_CHILDREN_DIVS) {
        let childDivs = document.querySelectorAll(".child-div");
        console.log("CHILD DIVS");
        console.log(childDivs);
        let lastChild = childDivs[childDivs.length - 1];
        lastChild.parentNode.removeChild(lastChild);
        NUM_OF_CHILDREN_DIVS--;
      }
    }
  }
}
