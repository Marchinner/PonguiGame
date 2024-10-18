#include "BaseEntity.h"

#include <glad/glad.h>

BaseEntity::BaseEntity(Type type, glm::vec3 position, glm::vec3 velocity, Shader* shader) :
	mType{ type },
	mPosition{ position },
	mVelocity{ velocity },
	mShader{ shader }
{
	constexpr float triangleVertices[]{
		// positions       
		 0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		 0.0f,  0.5f, 0.0f,
	};

	constexpr unsigned int triangleIndices[]{
		0, 1, 2
	};

	constexpr float paddleVertices[]{
		 0.5f,  0.5f, 0.0f,  // top right
		 0.5f, -0.5f, 0.0f,  // bottom right
		-0.5f, -0.5f, 0.0f,  // bottom left
		-0.5f,  0.5f, 0.0f   // top left 
	};

	constexpr unsigned int paddleIndices[]{
		0, 1, 3,   // first triangle
		1, 2, 3    // second triangle
	};

	constexpr float ballVertices[]{
		0.0f
	};

	constexpr unsigned int ballIndices[]{
		0
	};

	glGenVertexArrays(1, &mVAO);
	glGenBuffers(1, &mVBO);
	glGenBuffers(1, &mEBO);

	glBindVertexArray(mVAO);

	glBindBuffer(GL_ARRAY_BUFFER, mVBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mEBO);
	switch (mType)
	{
	case TRIANGLE:
		glBufferData(GL_ARRAY_BUFFER, sizeof(triangleVertices), triangleVertices, GL_STATIC_DRAW);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triangleIndices), triangleIndices, GL_STATIC_DRAW);
		break;
	case PADDLE:
		glBufferData(GL_ARRAY_BUFFER, sizeof(paddleVertices), paddleVertices, GL_STATIC_DRAW);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(paddleIndices), paddleIndices, GL_STATIC_DRAW);
		break;
	case BALL:
		glBufferData(GL_ARRAY_BUFFER, sizeof(ballVertices), ballVertices, GL_STATIC_DRAW);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(ballIndices), ballIndices, GL_STATIC_DRAW);
		break;
	default:
		break;
	}

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void BaseEntity::Update()
{
}

void BaseEntity::Draw()
{
	glBindVertexArray(mVAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void BaseEntity::Move(Direction direction)
{
	glm::vec3 moveVector;
	switch (direction)
	{
	case UP:
		moveVector = glm::vec3(0.0f, 0.1f, 0.0f);
		break;
	case LEFT:
		moveVector = glm::vec3(-0.1f, 0.0f, 0.0f);
		break;
	case DOWN:
		moveVector = glm::vec3(0.0f, -0.1f, 0.0f);
		break;
	case RIGHT:
		moveVector = glm::vec3(0.1f, 0.0f, 0.0f);
		break;
	default:
		moveVector = glm::vec3(0.0f, 0.0f, 0.0f);
		break;
	}
	glm::vec4 position{ mPosition, 1.0 };
	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::translate(trans, moveVector);
	position = trans * position;
	mPosition = position;
}

glm::vec3 BaseEntity::GetPosition() const
{
	return mPosition;
}

glm::vec3 BaseEntity::GetVelocity() const
{
	return mVelocity;
}
