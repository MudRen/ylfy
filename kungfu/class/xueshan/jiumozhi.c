// /kungfu/class/xueshan/jiumozhi.c �Ħ��
// by secret
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("�Ħ��", ({ "jiumo zhi", "zhi" ,"ming wang"}));
        set("nickname", HIG "��������" NOR);
        set("long",@LONG
������ѩɽ�µ����ţ��˳ƴ����������Ħ�ǡ����Է��о�����о���
��һ��������ģ�ͷ��ɮñ��
LONG);
        set("title","ѩɽ������");
        set("gender", "����");
        set("age", 60);
       set("attitude", "peaceful");
        set("str", 60);
        set("int", 60);
        set("con", 80);
        set("dex", 180);
        set("max_qi", 1500000);
        set("max_jing", 1075000);
        set("neili", 1500000);  //2015.9�޸��������ż����npc��ǿ��
        set("max_neili", 400000);
        set("jiali", 8000);
		set("xyzx_sys/level", 1200);
        set("combat_exp", 6400000);
        set_skill("force", 2400);
        set_skill("xiaowuxiang", 1400);
        set_skill("dodge", 2400);
        set_skill("shenkong-xing", 1400);
        set_skill("unarmed", 2420);
        set_skill("yujiamu-quan", 1400);
        set_skill("parry", 2400);
        set_skill("sword", 2400);
        set_skill("mingwang-jian", 1400);
        set_skill("mizong-xinfa", 1400);
        set_skill("literate", 1400);
        set_skill("staff", 2400);
        set_skill("xiangmo-chu", 1400 );
        set_skill("huoyan-dao", 1420);
       set_skill("necromancy", 1320);   	

        map_skill("force", "xiaowuxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "huoyan-dao");
        map_skill("parry", "mingwang-jian");
        map_skill("sword", "mingwang-jian");
        map_skill("staff", "xiangmo-chu");
        create_family("ѩɽ��", 1, "����");
        set("class", "bonze");
        setup();
//        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/xueshan/obj/r-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
        add_money("gold",1);
}
void attempt_apprentice(object ob)
{
          if ((string)ob->query("gender") != "����") {
                     command("say ��ϰ�����ڹ���Ҫ����֮�塣");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "������ذɣ�");
                return;
          }
          if ((string)ob->query("class") != "bonze") {
                     command("say �ҷ��ŵ����������ࡣ");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "������ذɣ�");
                return;
          }
        if ((string)ob->query("family/family_name") != "ѩɽ��"){
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�ȷǱ��µ��ӣ�������ذɣ�");
                return;
          }
        if ((int)ob->query_skill("mizong-xinfa", 1) < 100) {
                command("say ����ѩɽ�£���ϰ�����ķ�����Ҫ�ġ�");
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�ö�����б��ŵ��ķ���");
                return;
        }
//        command("chat ������������������");
//        command("chat ��ѩɽ�����Ǻ�����ˣ����ǿ�ϲ�ɺء�");
//        command("chat ������������������");
        command("recruit " + ob->query("id"));
    ob->set("title",HIY"����"NOR);
}
