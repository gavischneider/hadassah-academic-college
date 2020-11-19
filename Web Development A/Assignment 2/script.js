let NUM_OF_CHILDREN_DIVS = 0;

document.addEventListener("DOMContentLoaded", () => {
  document.getElementById("warning-message").style.display = "none";
  document.getElementById("button").addEventListener("click", handleSubmit);
  window.addEventListener("keyup", handleKeyUp);
});

function handleSubmit() {
  // Get all the inputs
  let errors = [];
  let firstName = document.getElementById("first-name-input").value;
  let lastName = document.getElementById("last-name-input").value;
  let birthYear = document.getElementById("birth-year-input").value;
  let immigrationYear = document.getElementById("immigration-year-input").value;

  if (!firstName) {
    errors.push("First name is missing");
  }
  if (!lastName) {
    errors.push("Last name is missing");
  }
  if (!birthYear) {
    errors.push("Birth year is missing");
  }
  if (!immigrationYear) {
    errors.push("Immigration year is missing");
  }
  if (birthYear > immigrationYear) {
    errors.push("Immigration year should be after birth");
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
    errors.map((error) => {
      newError = document.createElement("li");
      newError.textContent = error;
      listOfErrors.appendChild(newError);
    });
    let warningMessage = document.getElementById("warning-message");
    warningMessage.appendChild(listOfErrors);
    warningMessage.style.display = "block";
  }
}

function handleKeyUp() {
  console.log("Key down");
  let numOfChildren = document.getElementById("num-of-children-input").value;

  console.log("numOfChildren / NUM_OF_CHILDREN_DIVS");
  console.log(`${numOfChildren} / ${NUM_OF_CHILDREN_DIVS}`);

  // Check if key was a number
  if (!isNaN(numOfChildren)) {
    let childrenForm = document.getElementById("children-form");
    if (numOfChildren > NUM_OF_CHILDREN_DIVS) {
      // We need more divs for children
      while (numOfChildren > NUM_OF_CHILDREN_DIVS) {
        let newChildDiv = document.createElement("div");
        newChildDiv.setAttribute("class", "child-div");
        let label = document.createElement("label");
        label.textContent = `Child Name ${NUM_OF_CHILDREN_DIVS + 1}: `;
        newChildDiv.appendChild(label);
        let input = document.createElement("input");
        input.setAttribute("type", "text");
        input.setAttribute("class", "form-control");
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
