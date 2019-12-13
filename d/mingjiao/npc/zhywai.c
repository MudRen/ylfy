// zhywai.c
inherit NPC;
void create()
{
        set_name("张员外", ({ "zhang yuanwai"}));
        set("gender", "男性");
        set("age", 55);

        set_skill("unarmed", 30);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 10);
        set("attitude","heroism");
        set("inquiry", ([
           "牛" : "我这几天倒是得到头牛，你问这个干嘛，又不关你的事情。",
           "买牛" : "这个牛是个宝贝，听说和什么东西有关，我可不卖。",
        ]) );

        set("combat_exp", 25000);
        set("shen_type", -1);
        setup();
        carry_object("/clone/cloth/cloth")->wear();
        set("chat_chance", 10);
        set("chat_msg", ({
           "张员外大骂道：他奶奶的！我的宝贝在哪里。\n",
           "张员外说：你们都想要我的钱，也不打听一下我张员外是个什么样的人!哼\n",
           }) );
}

