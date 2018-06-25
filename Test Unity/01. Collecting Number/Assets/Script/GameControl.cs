using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameControl : MonoBehaviour
{
    static public GameControl instance;
    public bool GameOver = false;
    public bool LevelOver = false;
    public bool LevelPass = false;
    public bool OutOfChance = false;
    public float BoxFallSpeed = 3f;

    public int MinScoreBox = 1;
    public int MaxScoreBox = 10;

    public int ChanceNegativeScore = 0;
    public float ColourChangeDelay = 1f;
    public float CurrentDelay = 0f;

    private int Score = 0;
    private int Level = 1;
    private int Target = 10;
    private int Chance = 3;

    public Text LevelText;
    public Text TargetText;
    public Text ScoreText;
    public Text ChanceText;

    void Awake()
    {
        if (instance == null)
        {
            instance = this;
        }
        else if (instance != this)
        {
            Destroy(gameObject);
        }
    }

    void Update()
    {
        if (LevelOver && Score >= Target)
        {
            LevelPass = true;
            UpdateProperties();
            UpdateScoreBoard();
        }
    }

    public void PlayerScored(int ScoreInBox)
    {
        Score += ScoreInBox;
        ScoreText.text = "SCORE: " + Score.ToString();
    }

    public void PlayLoseChance()
    {
        Chance--;
        ChanceText.text = "CHANCE: " + Chance.ToString();
        if (Chance == 0) OutOfChance = true;
    }

    private void UpdateProperties()
    {
        Level++;
        Chance = 3;
        Target += 15;
        OutOfChance = false;
        LevelOver = false;
        BoxCounter.counter = 0;

        ChanceNegativeScore = Level / 2;
        if (ChanceNegativeScore > 5)
        {
            ChanceNegativeScore = 5;
            Target += 7;
        }
        
        if (BoxFallSpeed <= 6f)
        {
            BoxFallSpeed += 1f;
            ColourChangeDelay *= 0.8f;
        }
    }

    private void UpdateScoreBoard()
    {
        LevelText.text = "LEVEL " + Level.ToString();
        TargetText.text = "TARGET: " + Target.ToString();
        ScoreText.text = "SCORE: " + ToString();
        ChanceText.text = "CHANCE: " + Chance.ToString();
    }
}