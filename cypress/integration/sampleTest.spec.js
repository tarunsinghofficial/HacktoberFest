describe("Sample Test", () => {
  it('Check for "Masai Open Source"', () => {
    cy.visit("http://localhost:3000");
    cy.contains("Masai Open Source");
  });
});
