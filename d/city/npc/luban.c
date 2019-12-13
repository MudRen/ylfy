// guoguo
inherit NPC;
int ask_party(string str);
void create()
{
    set_name("³��", ({ "lu ban", "lu" }));
    set("title", HIY"��"NOR); 
    set("gender", "����");
    set("age", 35);
    set("str", 50000);          
    set("dex", 15);
    set("int", 35);
    set("con", 35);
    set("long", "������ʦ,�й����֮��,������컯֮��,������֮��Զ������ ��\n");      
    set("combat_exp", 1500000000);
    set("shen", 0);     
    set_skill("unarmed", 3500);
    set_skill("force", 3500);
    set_skill("dodge", 3500);
    set_skill("parry", 3500);
    set_skill("axe", 3500);
    set_skill("qufeng", 3500);  
    set_skill("qishang-quan", 3500);            
    set_skill("wuxue-shenfa", 3500);            
    set_skill("king-of-dragon", 3500);          
    set_skill("leiting-axe", 3500);
    map_skill("force", "king-of-dragon");       
    map_skill("dodge", "wuxue-shenfa"); 
    map_skill("axe", "leiting-axe");
    map_skill("parry", "leiting-axe");  
    map_skill("unarmed", "qishang-quan");               
    set_temp("apply/attack", 150);
    set_temp("apply/defense", 150);
    set_temp("apply/armor", 150);
    set_temp("apply/damage", 350);
    set("jiali", 1500); 
    set("max_neili", 5000);     
    set("neili", 15000000);     
    set("max_qi", 1000000);     
    set("max_jingli", 150000);  
    set("jingli", 1500000);     
    set("max_jing", 1000000);   
    set("chat_chance_combat", 150);
    set("chat_msg_combat", ({
        (: perform_action, "axe.zhentian" :),
        (: perform_action, "unarmed.hunpofeiyang" :),           
      }) );
    set("inquiry", ([
        "����": (: ask_party :),
      ]) );
    setup();
    carry_object("/d/gaochang/obj/goldaxe")->wield();   
    carry_object("/clone/npc/obj/golden_armor")->wear();        
    carry_object("/clone/cloth/zixuan")->wear();                
}

void init()
{
    add_action("make_bang","mkbang");
}

int ask_party(string arg)
{
    write(YEL"ʹ�÷�����mkbang <Ӣ�İ���id> <���İ�������>\n"NOR);
    return 1;
}

private string *rooms=({
        "dating.c",
        "guanchang.c",
        "beidajie1.c",
        "beidajie2.c",
        "beidajie3.c",
        "beidajie4.c",
        "beidajie5.c",
        "nandajie5.c",
        "nandajie4.c",
        "nandajie3.c",
        "nandajie2.c",
        "nandajie1.c",
        "xidajie1.c",
        "xidajie2.c",
        "xidajie3.c",
        "xidajie4.c",
        "xidajie5.c",
        "dongdajie5.c",
        "dongdajie4.c",
        "dongdajie3.c",
        "dongdajie2.c",
        "dongdajie1.c",
        "leitai.c",
});
int make_bang(string arg)
{
    string partyid,partyname;
    object me;
    int i;
    me=this_player();
    if(!arg || arg=="" || sscanf(arg,"%s %s",partyid,partyname)!=2)
    {
        write(YEL"ʹ�÷�����mkbang <Ӣ�İ���id> <���İ�������>\n"NOR);
        return 1;
    }
    if(!me->query("xy_huiyuan"))
    {
        command("say �Բ���ֻ�л�Ա���ܽ��");
        return 1;
    }
    if (me->query("more_money") < 100)
    {
        command("say �Բ�������ʽ���,������̣�����Ҫ��һ�����");
        return 1;
    }
    if(me->query("xyzx_sys/level") < 100)
    {
        command("say �㼶�����㣬���Գ�Ϊһ��֮�������㵽��һ�ټ������ɡ�");    
        return 1;       
    }
    if(sizeof(partyid)==0||sizeof(partyname)==0)
    {
        command("say ����id���߰���������Ϊ�ա�");
        return 1;
    }
    if(me->query("party/id"))
    {
        command("say ��������˳�ԭ���İ��ɡ�");
        return 1;
    }
    for(i=0;i<sizeof(partyid);i++)
    {
        if(partyid[i]<'a' || partyid[0] > 'z')
        {
            command("say ����id������СдӢ����ĸ��");
            return 1;
        }
    }
    if(sizeof(partyname)%2!=0)
    {
        command("say ���������������ġ�");
        return 1;
    }
    for(i=0;i<sizeof(partyname);i++)
    {
        if( partyname[i]<=' ' ) {
            command("say �����������Ʋ����ÿ�����Ԫ��");
            return 1;
        }
        if( i%2==0 && !is_chinese(partyname[i..(i+1)]) ) {
            command("say ������������ֻ�������ġ�");
            return 1;
        }
    }
    if(file_size("/d/party/"+partyid)==-2)
    {
        command("say �������id�Ѿ���ʹ�á�");
        return 1;
    }

    if(mkdir("/d/party/" + partyid)==0)
    {
        tell_object(me,"����Ŀ¼����ʧ�ܣ�����ϵ��ʦ��\n");
        return 1;
    }
    for(i=0;i<sizeof(rooms);i++)
    {
        if(!cp("/d/party/"+rooms[i],"/d/party/"+partyid+"/"))
        {
            tell_object(me,"�����ļ�����ʧ�ܣ�����ϵ��ʦ��\n");
            return 1;
        }
    }
    me->set("party/id",partyid);
    me->set("party/zhu",1);     
    me->add("more_money",-100); 
    me->set("party/name",partyname);    
    me->set("bh_rank",HIC"����"NOR);
    message("channel:chat", HIY"\n�����ɾ��顿"+HIM"��"+me->query("name")+"�ڽ��տ������ᣬ����"+partyname+"�����Ϊ֮�����ʡ�\n"NOR,users());
    write_file("/log/cmds/party",sprintf("%s   ��������   %s%s on %s\n", me->query("id"),partyname,"("+partyid+")", ctime(time()) ));
    return 1;
}

