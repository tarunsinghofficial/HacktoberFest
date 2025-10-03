## Cypress
Cypress is “Fast, easy and reliable testing for anything that runs in a browser”. What you get with Cypress is a tool that makes it simple to set up, write, run, and debug tests.

Cypress documentation : 
https://docs.cypress.io/guides/core-concepts/introduction-to-cypress.html#Cypress-Can-Be-Simple-Sometimes

Video Link:
https://www.youtube.com/watch?v=KfTH2d-JZ6k&list=PL8GlT7H3xOcJbXNVnM6lTT3Fec8dikotY

## How To Write a Test Case In Cypress

### Begin with writing describe keyword with Relevant text required for test cases for that particular pg.

```
describe('testcase_pg1',()=>{})

```


### Inside describe start an anonymous function which will contain test for that particular file/page . The test case starts with it('testcase name',()=>{....})

```
describe('Input form',()=>{
    it('test1',() =>{
       
    })
})

```


### Inside one test case you can check for the conditions you want to check for that particular test case .




#### The condition starts with cy which has further methods  For example in this test_case cy.visit('address') helps us to reach the link inside method .

```
describe('Input form',()=>{
    it('visit the address ',() =>{
        cy.visit('http://localhost:3000/')
    })
})

```

### If you want to check there exists a form which has a submit button with value 'submit the form!'

#### So the html for the finding the element:- 


 ```html
 <form>
    <div>
      <label>name</label>
      <input name="name" />
    </div>
    <div>
      <label>age</label>
      <input name="age" />
    </div>
    <input type="submit" value="submit the form!" />
  </form>
  
  ```


  To check whether the submit button is present or not the cypress query will be

  ```
  cy.get('form').contains('submit the form!').click()

  ```
  this will ensure that whether theres a element which contains the value submit the form! which is under form tag.



### You can also check the http request using cy.request(url, body, method , options)
for example:-

```
cy.request({
  method: 'POST',
  url: '/login_with_form', // baseUrl is prepended to url
  form: true, // indicates the body should be form urlencoded and sets Content-Type: application/x-www-form-urlencoded headers
  body: {
    username: 'jane.lane',
    password: 'password123'
  }
})
```