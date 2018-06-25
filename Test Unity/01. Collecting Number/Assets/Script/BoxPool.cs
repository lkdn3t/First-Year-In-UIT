using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BoxPool : MonoBehaviour
{
    public int NumberOfBox = 12;
    public float DistanceFromBox = 4f;
    public GameObject BoxPrefab;

    private Vector2 PoolPosition = new Vector2(-15f, -25f);
    private float SpawnXPosition = -5f;
    private GameObject[] BoxObject;

    void Start()
    {
        InitializeBoxPool();
    }

    void Update()
    {
        if (BoxCounter.counter == NumberOfBox)
            GameControl.instance.LevelOver = true;

        if (GameControl.instance.LevelPass && Input.GetMouseButtonDown(0))
        {
            GameControl.instance.LevelPass = false;
            DestroyBoxPool();
            InitializeBoxPool();
        }
    }

    void InitializeBoxPool()
    {
        float SpawnYPosition = 8f;
        if (BoxObject == null)
            BoxObject = new GameObject[NumberOfBox];
        
        for (int i = 0; i < NumberOfBox; i++)
        {
            BoxObject[i] = (GameObject)Instantiate(BoxPrefab, PoolPosition, Quaternion.identity);
            BoxObject[i].transform.position = new Vector2(SpawnXPosition, SpawnYPosition);
            SpawnYPosition += DistanceFromBox;
        }
    }

    void DestroyBoxPool()
    {
        for (int i = 0; i < NumberOfBox; i++)
            Destroy(BoxObject[i]);
    }
}