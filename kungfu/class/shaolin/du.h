// du.h for apprentice.
//Hop 1997.01.23
void attempt_apprentice(object ob)
{
    object me  = this_object();
    mapping ob_fam;
    mapping my_fam  = me->query("family");
    string name, new_name;
    name = ob->query("name");
    if (stringp(ob->query("marry"))){
        command("say ��λ" + RANK_D->query_respect(ob) + "��Դδ�ˣ��������ҿ��ţ�");
        return;
    }
    if ( ob->query("betrayer") >= 2)
    {
        command("say " + RANK_D->query_respect(ob) + "��ʦ����̫���ˣ��Ҳ������㡣");
        return;
    }
    if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
    {
        command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
        return;
    }
    if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
    {
        command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
        return;
    }
    if ( ob_fam["generation"] <= my_fam["generation"] )
    {
        command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
        return;
    }
    if ( ob_fam["generation"] == (my_fam["generation"] + 1) )
    {
        command("say " + ob_fam["master_name"] + "��ͽ�������ܵ���������ˣ������� !");
        command("recruit " + ob->query("id"));
    }
    if (ob->query("family/generation") == 37)
    {
        if ((int)ob->query_skill("dodge", 1) < 120 ||
            (int)ob->query_skill("parry", 1) < 120 ||
            (int)ob->query_skill("force", 1) < 120 ||
            (int)ob->query_skill("buddhism", 1) < 120 ||
            (int)ob->query_skill("hunyuan-yiqi", 1) < 120 ||
            (int)ob->query_skill("shaolin-shenfa", 1) < 120) {
            command("say " + "���Ƿ�Ӧ���ڸ�����϶��µ㹦��");
            return;
        }
        command("chat ����������������");
        command("chat �벻�������ڴ���֮�꣬���ٵ�һ������֮�ţ����ǿ�ϲ�ɺء�");
        command("recruit " + ob->query("id"));
    
        command("say ��" + ob_fam["master_name"] + "���������ҵİɣ������� !");
        command("say ƶɮ�ֵ�һ����֮�ţ����ǿ�ϲ�ɺ� !");
        name = ob->query("name");
        new_name = "��" + name[2..3];
        ob->set("name", new_name);
        ob->set("family/generation",36);
        command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ���������ֱ����� !");
        command("recruit " + ob->query("id"));
    }
}
