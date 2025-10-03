import React, { Component } from "react";
import GitHubLogin from "react-github-login";

class GithubOauth extends Component {
  githubResponse = () => {};

  render() {
    return (
      <div>
        <GitHubLogin
          clientId={process.env.REACT_APP_GITHUB_CLIENT_ID}
          scope="user:email"
          onSuccess={this.githubResponse}
          onFailure={this.githubResponse}
        />
      </div>
    );
  }
}

export default GithubOauth;
