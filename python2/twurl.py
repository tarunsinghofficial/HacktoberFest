import urllib.request, urllib.parse, urllib.error
import oauth
import hidden

def argument(url, parameters):
	secrets = hidden.oauth()
	customer = oauth.OAuthCunsumer(secrets['customer_key'], secrets['customer_secret'])
	token = oauth.OAuthToken(secrets['token'])
	oauth_request = oauth.OAuthToken.from_customer_and_token(customer, token=token, http_method='GET', http_url=url, parameters=parameters)
	oauth_request.sign_request(oauth.OAuthSignatureMethod_HMAC_SHA1(), customer, token)
	return oauth_request.to_url()