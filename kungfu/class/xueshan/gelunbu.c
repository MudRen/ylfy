//
// /kungfu/class/xueshan/gelunbu.c  ���ײ�
// by secret
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("����", ({ "gelunbu", "ge" }));
        set("long",@LONG
������ѩɽ���л���ɮ����ͷ�졣ͬʱ���µ��Ӵ����书��
��һ����ɫ���ģ�ͷ��ɮñ��
LONG
        );
        set("title", HIY "����" NOR);
        set("nickname", HIG "ɮ��ͷ��" NOR);
        set("gender", "����");
        set("age", 30);
        set("attitude", "heroism");
        set("str", 30);
        set("int", 20);
        set("con", 28);
        set("dex", 25);
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 20);
        set("combat_exp", 1000000);
        set_skill("mizong-xinfa", 100);
        set_skill("literate", 110);
        set_skill("force", 110);
        set_skill("longxiang", 110);
        set_skill("dodge", 115);
        set_skill("shenkong-xing", 110);
        set_skill("parry", 110);
        set_skill("staff", 110);
        set_skill("xiangmo-chu", 110 );
        set_skill("hammer",110);
        set_skill("riyue-lun",110);
        set_skill("unarmed", 110);
        set_skill("yujiamu-quan", 110);


        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("parry", "xiangmo-chu");
        map_skill("staff", "xiangmo-chu");
        map_skill("hammer","riyue-lun");
        map_skill("unarmed","yujiamu-quan");
        create_family("ѩɽ��", 5, "����");
        set("class", "bonze");
        setup();
        carry_object("/d/xueshan/obj/b-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
        carry_object("/d/xueshan/obj/senggun")->wield();
        add_money("silver",30);
}
void attempt_apprentice(object ob)
{
        if ((string)ob->query("gender") != "����") {
                command("say ��ϰ�����ڹ���Ҫ����֮�塣");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "������ذɣ�");
                return;
        }
        command("say �Ҿʹ���һЩ�书�ɣ�");
        command("recruit " + ob->query("id"));
        if((string)ob->query("class") != "bonze")       {
                ob->set("title","�׼ҵ���");
        }
        else    {
                ob->set("title",HIY"С����"NOR);
        }
        
}
