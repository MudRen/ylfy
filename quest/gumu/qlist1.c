inherit SKILL;
mapping *quest = ({
        ([      "quest":                "֪�͵���",               
                "quest_type":           "ɱ",
                "time":                 800,
                "score" :               9
        ]),
        ([      "quest":                "���",
                "quest_type":           "ɱ",
                "time":                 900,
                "score" :               10
        ]),
        ([      "quest":                "��åͷ",
                "quest_type":           "ɱ",
                "time":                 500,
                "score" :               5
        ]),
         ([      "quest":                "ľ���",
                "quest_type":           "Ѱ",
                "time":                 600,
                "score" :               10
        ]),
        ([      "quest":                "��־ƽ",
                "quest_type":           "ɱ",
                "time":                 800,
                "score" :               12
        ]),       
        ([      "quest":                "��־ƽ",
                "quest_type":           "ɱ",
                "time":                 800,
                "score" :               12
        ]),  
        ([      "quest":                "С����",
                "quest_type":           "ɱ",
                "time":                 800,
                "score" :               10
        ]),  
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 800,
                "score" :               10
        ]),
        ([      "quest":                "���¾�",
                "quest_type":           "Ѱ",
                "time":                 400,
                "score" :               4
        ]),
        ([      "quest":                "����",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               6
        ]),
        ([      "quest":                "��Ա��",
                "quest_type":           "ɱ",
                "time":                 600,
                "score" :               10
        ]),           
 
});


mapping query_quest()
{
        return quest[random(sizeof(quest))];
}

