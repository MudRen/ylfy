mapping *quest = ({
     ([      "quest":                "�η�Կ��",
        "diff":                 3,
        ]),
     ([      "quest":                "��ˮ��",
        "diff":                 3,
        ]),
     ([      "quest":                HIC "��ɽ����" NOR,
        "diff":                 2,
        ]),
     ([      "quest":                "���ɲ�",
        "diff":                 2,
        ]),
     ([      "quest":                "�����ľ�",
        "diff":                 4,
        ]),
     ([      "quest":                HIY"��ɫ����"NOR,
        "diff":                 3,
        ]),
     ([      "quest":                "���¾�����ʮ���¡�",
        "diff":                 2,
        ]),
     ([      "quest":                "���",
        "diff":                 3,
        ]),
     ([      "quest":                "���¾����ڶ��¡�",
        "diff":                 2,
        ]),
         
});
mapping query_quest()
{
        return quest[random(sizeof(quest))];
}
