mapping *quest = ({
        ([      "quest":                "ͭ��",
                "diff":                 2,
        ]),
        ([      "quest":                "����",
                "diff":                 1,
        ]),
     ([      "quest":                "�ֲ���",
                "diff":                 2,
        ]),
     ([      "quest":                "���⴮",
        "diff":                 2,
        ]),
     ([      "quest":                "��",
        "diff":                 2,
        ]),  
    ([      "quest":                "����",
        "diff":                 2,
        ]),
    ([      "quest":                "�ֵ�",
        "diff":                 2,
        ]),
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
