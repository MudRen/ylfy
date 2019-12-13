
inherit NPC;
inherit F_UNIQUE;
void create()
{
    set_name("����", ({
        "ao bai",
        "ao",
        "bai",
    }));
    set("long",
        "���������޵�һ��ʿ����һϮ��߽��С�����Ŀ��࣬\n"
        "��ò������̫��Ѩ�߸߹����ƺ��������书��\n"
    );
    set("nickname", "���޵�һ��ʿ");
    set("gender", "����");
    set("attitude", "aggressive");
    set("age", 50);
    set("shen_type", -1);
    set("str", 25);
    set("int", 25);
    set("con", 25);
    set("dex", 25);
    set("max_qi", 1500);
    set("max_jing", 1500);
    set("neili", 1500);
    set("max_neili", 1500);
    set("jiali", 150);
    set("combat_exp", 4280000);
    set("score", 50000);
    set_skill("force", 310);
    set_skill("hunyuan-yiqi", 210);
    set_skill("dodge", 350);
    set_skill("shaolin-shenfa", 300);
    set_skill("unarmed", 300);
    set_skill("parry", 300);
    set_skill("literate", 55);
    set_skill("fengyun-shou", 280);
    map_skill("force", "hunyuan-yiqi");
    map_skill("dodge", "shaolin-shenfa");
    map_skill("unarmed", "fengyun-shou");
    map_skill("parry", "fengyun-shou");
        set("chat_chance_combat", 10);  
        set("chat_msg_combat", ({
                " ����ŭ������Ҳ�����˯�������������� ��\n",
                (: command("say ������������" + RANK_D->query_rude(this_player())+"!\n") :),
        (: command("pain") :),
                      }) );
        setup();
        carry_object("/d/city2/obj/anmenkey")->wield();
        carry_object("/d/city2/obj/jinduan")->wear();
        carry_object("/d/city2/obj/yaodai")->wear();
        carry_object("/d/city2/obj/yaoshi")->wield();
        add_money("gold",10);
}
void die()
{
        message("vision","\n���ݿ�е����벻����һ��������Ȼ�������֣�\n","/d/city2/aobai6");            
        message("vision","���ݶ���һ�٣�̾��������ֻ��ϧ�ҵ���ô�౦������\n","/d/city2/aobai6");            
        message_vision("$N����һ�������ˣ�\n", this_object());
        ::die();
}
#include "/kungfu/class/shaolin/cheng.h"
