mapping *quest = ({
     ([      "quest":                "���õ�ʬ��",
                "diff":                 3,
        ]),
     ([      "quest":                "ɳ���",
                "diff":                 3,
        ]),
        ([      "quest":                "ͭ��",
                "diff":                 2,
        ]),
        ([      "quest":                "���",
                "diff":                 1,
        ]),
     ([      "quest":                "ά����峤��",
                "diff":                 2,
        ]),
     ([      "quest":                "ţƤ��",
        "diff":                 2,
        ]),
     ([      "quest":                "������",
        "diff":                 2,
        ]),
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
