// Check if the user is authenticated
function userIsAuthenticated(session) {
  if (session.user) {
    return true;
  } else {
    console.log("FALSE");
    return false;
  }
}

module.exports = userIsAuthenticated;
