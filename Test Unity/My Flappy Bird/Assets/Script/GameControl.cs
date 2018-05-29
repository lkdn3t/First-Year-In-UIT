using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class GameControl : MonoBehaviour
{
    public static GameControl instance;
    public GameObject GameOverText;
    public Text ScoreText;

    public bool GameOver = false;
    public float ScrollSpeed = -1.5f;
    public int Score = 0;

    //Khởi tạo controller cho game, Awake gọi trước khi bắt đầu game
    void Awake()
    {
        //Nếu chưa có controller: tạo mới
        if (instance == null)
        {
            instance = this;
        }
        //Nếu đã có: huỷ controller này vì đã bị trùng
        else if (instance != this)
        {
            Destroy(gameObject);
        }
    }

    //Cập nhật lại frame: nếu GameOver thì hiển thị các Screen bị ẩn
    //cụ thể là scene báo GameOver
    void Update()
    {
        if (GameOver && Input.GetMouseButtonDown(0))
        {
            SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex);
        }
    }

    public void BirdScored()
    {
        if (GameOver) return;
        Score++;
        ScoreText.text = "Score: " + Score.ToString();
    }

    //Khi chim chết: Hiển thị thông báo GameOver và đặt kết thúc game
    public void BirdDied()
    {
        GameOverText.SetActive(true);
        GameOver = true;
    }
}