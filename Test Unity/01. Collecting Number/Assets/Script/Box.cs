using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Box : MonoBehaviour
{
    public Text ScoreTextBox;
    public int ScoreInBox;

    private Rigidbody2D rgbd;
    private bool isInHitBoxCollision = false;
    private bool isScored = false;

    void Start()
    {
        rgbd = GetComponent<Rigidbody2D>();
        rgbd.velocity = new Vector2(0, -GameControl.instance.BoxFallSpeed);
        InitializeBox();
    }

    void Update()
    {
        CheckInHitBox();
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.GetComponent<Arrow>() != null)
        {
            isInHitBoxCollision = true;
            GameControl.instance.CurrentDelay = Time.time + GameControl.instance.ColourChangeDelay;
        }

        if (collision.GetComponent<BoxCounter>() != null)
        {
            BoxCounter.counter++;
            rgbd.velocity = Vector2.zero;
        }
    }

    private void InitializeBox()
    {
        ScoreTextBox = GetComponentInChildren<Text>();
        ScoreInBox = Random.Range(GameControl.instance.MinScoreBox, GameControl.instance.MaxScoreBox);
        ScoreTextBox.text = Mathf.Abs(ScoreInBox).ToString();

        if (Random.Range(0, 10) < GameControl.instance.ChanceNegativeScore)
        {
            ScoreInBox = -ScoreInBox;
            transform.GetComponent<Renderer>().material.color = Color.red;
        }
    }

    private void CheckInHitBox()
    {
        if (isInHitBoxCollision)
        {
            transform.GetComponent<Renderer>().material.color = Color.green;
            if (Input.GetMouseButtonDown(0) && !isScored & !GameControl.instance.OutOfChance)
            {
                GetScoreBox();
            }

            if (Time.time >= GameControl.instance.CurrentDelay)
            {
                ReColourBox();
            }
        }
    }

    private void GetScoreBox()
    {
        isScored = true;
        isInHitBoxCollision = false;
        transform.GetComponent<Renderer>().material.color = Color.yellow;
        GameControl.instance.PlayerScored(ScoreInBox);
        GameControl.instance.PlayLoseChance();
    }

    private void ReColourBox()
    {
        if (!isScored)
            if (ScoreInBox > 0) transform.GetComponent<Renderer>().material.color = Color.white;
            else transform.GetComponent<Renderer>().material.color = Color.red;
        isInHitBoxCollision = false;
    }
}