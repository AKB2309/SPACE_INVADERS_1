#pragma once
class Enemy
{
public:
	Enemy();
	Enemy(const Enemy& obj);
	Enemy(Enemy&& obj);
	virtual ~Enemy();

	Enemy& operator=(const Enemy& obj);

	int getDirection() const;
	void setDirection(int dir);


	
protected:
	int direction;
};

