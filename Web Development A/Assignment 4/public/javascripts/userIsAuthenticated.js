// Check if the user is authenticated
function userIsAuthenticated(session) {
  console.log("IN THE USER IS AUTH FUNCTION!");
  if (session.user) {
    console.log("Session User !!!!!!!!");
    console.log(session.user);
    return true;
  } else {
    console.log("FALSE");
    return false;
  }
}

module.exports = userIsAuthenticated;
