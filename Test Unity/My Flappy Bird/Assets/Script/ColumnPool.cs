using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ColumnPool : MonoBehaviour {
    public int NumberOfColumns = 5;
    public GameObject ColumnPrefab;
    public float SpawnRate = 4f;
    public float ColumnMin = -1f;
    public float ColumnMax = 2f;

    private GameObject[] Columns;
    private Vector2 PoolPosition = new Vector2(-15f, -25f);
    private float TimeSinceLastSpawned;
    private float SpawnXPosition = 10f;
    private int CurrentColumn = 0;

	// Use this for initialization
	void Start () {
        Columns = new GameObject[NumberOfColumns];
        for (int i = 0; i < NumberOfColumns; i++) 
        {
            Columns[i] = (GameObject)Instantiate(ColumnPrefab, PoolPosition, Quaternion.identity);
        }
	}
	
	// Update is called once per frame
	void Update () {
        TimeSinceLastSpawned += Time.deltaTime;

        if (!GameControl.instance.GameOver && TimeSinceLastSpawned >= SpawnRate)
        {
            TimeSinceLastSpawned = 0;
            float spawnYPosition = Random.Range(ColumnMin, ColumnMax);
            Columns[CurrentColumn].transform.position = new Vector2(SpawnXPosition, spawnYPosition);
            CurrentColumn++;

            if (CurrentColumn >= NumberOfColumns)
            {
                CurrentColumn = 0;
            }
        }
	}
}