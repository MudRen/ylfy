mapping *quest = ({
     ([      "quest":                "��Ƥ",
        "diff":                 2,
        ]),
     ([      "quest":                "�廨СЬ",
        "diff":                 2,
        ]),
     ([      "quest":                "��Ƥ",
        "diff":                 2,
        ]),
     ([      "quest":                MAG "�ۺ����" NOR,
        "diff":                 2,
        ]),
     ([      "quest":                "����",
        "diff":                 2,
        ]),
     ([      "quest":                "���¾����¾�",
        "diff":                 2,
        ]),
     ([      "quest":                "����",
        "diff":                 2,
        ]),
     ([      "quest":                "�ִŴ���",
        "diff":                 2,
        ]),
     ([      "quest":                "ˮ����",
        "diff":                 2,
        ]),
        
        
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
