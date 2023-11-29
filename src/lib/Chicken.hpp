typedef struct {
	float x, y;	 //position of the chicken
	float size;
	bool  direction; //true for right
} chicken;

void drawChicken(const Chicken *chicken) {
	glPushMatrix();
	glTranslatef(chicken->x, chicken->y, 0.0f); //changes to the current position of the chicken
	
	//create square to represent the chicken
	glColor3f(1.0f, 1.0f, 0.0f); //Yellow
	glBegin(GL_QUADS);
		glVertex2f(-chicken->size, -chicken->size);
		glVertex2f(chicken->size, -chicken->size);
		glVertex2f(chicken->size, chicken->size);
		glVertex2f(-chicken->size, chicken->size);
	 glEnd();

	 glPopMatrix();
}
