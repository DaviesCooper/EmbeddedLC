#ifndef ABSTRACTSTATE_H
#define ABSTRACTSTATE_H

struct AbstractState
{
public:
	/**
	 * @brief Default constructor.
	 */
	AbstractState();

	/**
	 * @brief Default destructor.
	 */
	virtual ~AbstractState();

	/**
	 * @brief When entering this state do some preliminary actions.
	 *
	 */
	virtual void Enter();

	/**
	 * @brief When exiting this state do some non-memory cleanup.
	 *
	 */
	virtual void Exit();

	/**
	 * @brief What to do in the update method. Called once per frame by
	 * the cycle method.
	 *
	 */
	virtual void Update();

	/**
	 * @brief Perform update at most once per frame.
	 *
	 */
	void Cycle();

private:
	/**
	 * @brief The last time the frame got called.
	 *
	 */
	unsigned long lastFrame;

	/**
	 * @brief The last time debug timer was called.
	 */
	unsigned long lastDebug;

protected:
	/**
	 * @brief Perform this action when the P1 button is pressed.
	 *
	 */
	virtual void P1Pressed();

	/**
	 * @brief Perform this action when the M1 button is pressed.
	 *
	 */
	virtual void M1Pressed();

	/**
	 * @brief Perform this action when the PX button is pressed.
	 *
	 */
	virtual void PXPressed();

	/**
	 * @brief Perform this action when the MX button is pressed.
	 *
	 */
	virtual void MXPressed();

	/**
	 * @brief Perform this action when the Phi button is pressed.
	 *
	 */
	virtual void PhiPressed();

	/**
	 * @brief Perform this action when the Dice button is pressed.
	 *
	 */
	virtual void DicePressed();

	/**
	 * @brief Perform this action when the Mana button is pressed.
	 *
	 */
	virtual void ManaPressed();

	/**
	 * @brief Perform this action when the Timer button is pressed.
	 *
	 */
	virtual void TimerPressed();

	/**
	 * @brief Perform this action when the Back button is pressed.
	 *
	 */
	virtual void BackPressed();

	/**
	 * @brief Perform this action when the Rotary button is pressed.
	 *
	 */
	virtual void RotaryPressed();

	/**
	 * @brief What to do when the
	 */
	void cleanup();
};

#endif
