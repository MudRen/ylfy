inherit F_CLEAN_UP;


#define SCALE   (1.0/10.0)
#define STATUS  "����������......"

string memory_expression(int m);
string dotime();
nosave string ver_msg, mud_name, version;

int count_ppls();

void create() { seteuid(getuid(this_object())); }

void check(object *objs,string str)
{
	string file,*rename,info="";
	mapping ddd= ([]);
	int i,max,max2,max3;
	mixed *key,name,name2,name3;

	foreach(object ob in objs)
	{
		if (!ob)
			continue;
		file = file_name(ob);
		rename = explode(file,"#");
		if(!ddd[rename[0]])
			ddd[rename[0]] = 1;
		else
			ddd[rename[0]] += 1;
	}
	key = keys(ddd);
	for(i=0;i<sizeof(ddd);i++)
	{
		if(max <= ddd[key[i]])
		{
			max3 = max2;
			max2 = max;
			max = ddd[key[i]];
			name3 = name2;
			name2 = name;
			name = key[i];
		}
		if(ddd[key[i]] > 1)
			info += sprintf("%s  :%d\n", key[i],ddd[key[i]]);
	}

	write(NOR + WHT "\t\t ��������������������������������������������������\n");
	write(sprintf(NOR + WHT "\t\t %s\n",str));
	write(sprintf(NOR + WHT"\t\t 1.%s   %d�����\n\t\t 2.%s   %d�����\n\t\t 3.%s   %d�����\n"NOR,
																				name,max,name2,max2,name3,max3));
}

void check_room(object *objs)
{
	mapping ddd= ([]);
	string file,info="";
	object *alls;
	mixed *key;
	int i,size;

	write(NOR + WHT "\t\t ��������������������������������������������������\n");
	write(sprintf(NOR + WHT "\t\t %s\n","�˶�ķ���"NOR));

	foreach(object ob in objs)
	{
		if(!ob->is_room())
			continue;

		file = file_name(ob);
		alls = all_inventory(ob);
		size = sizeof(alls);
		if(15 < size)
			ddd[file] = size;
		
		if(size)
			info +=sprintf("%s  :%d\n"NOR, file,size);
	}

	key = keys(ddd);
	for(i=0;i<sizeof(ddd);i++)
	{
		write(sprintf(NOR + WHT"\t\t %s   %d�����\n"NOR,key[i],ddd[key[i]]));
	}
}

int main(object me) 
{
        float value;
        mapping r;
        object *objs =objects();
        object *hearts = heart_beats();
        
        if (time() - me->query_temp("scan_time") < 10
           && ! wizardp(me))
                return notify_fail("ϵͳ��æ�У����Ժ򡭡�\n");
        
	   reset_eval_cost();
	   
        if (!ver_msg)
                ver_msg = get_system_config(DATA_CONFIG_DIR "system.h", "MUD_VERSION");
        
        if (!mud_name)
                mud_name = MUD_NAME;
        
        if (!version)
                version = __VERSION__;
        r = rusage();
        value = SCALE * (r["utime"] + r["stime"]) / uptime();

        write(NOR + WHT "\n\t\t         .__________ ϵ ͳ �� Ѷ __________.\n");
        write(NOR + WHT "\t\t ��������������������������������������������������\n");
        write(NOR + WHT "\t\t ��Ϸ��ʶ�����ƣ�  " + mud_name + "\n");
        write(NOR + WHT "\t\t ����ϵͳ�İ汾��  " + version + "\n");
        write(NOR + WHT "\t\t ��Ϸ�����а汾��  Version " + ver_msg + "\n");
        printf(NOR + WHT "\t\t CPU ʹ�ðٷֱȣ�  %f %% �������Ϸʹ����\n", value );
        write(NOR + WHT "\t\t CPU �ĸ���״����  " + query_load_average() + "\n");
        printf(NOR + WHT "\t\t ��ʹ�õļ����壺  %s bytes\n", memory_expression(memory_info()) );
        write(NOR + WHT "\t\t ����ʹ����������  " + sizeof( users() ) + "  ����������\n");
        write(NOR + WHT "\t\t ע��ʹ����������  " + count_ppls() + "  �����ڱ���Ϸע��\n");
        write(NOR + WHT "\t\t ��������������  " + sizeof( objs ) + " �����\n");
        write(NOR + WHT "\t\t ������������Ѷ��  " + sizeof(hearts) + " ��\n");
        write(NOR + WHT "\t\t �ӳٺ�������Ѷ��  " + sizeof(call_out_info()) + " ��\n");
        write(NOR + WHT "\t\t ����ִ�е�ʱ�䣺  " + dotime() + "\n");
        write(NOR + WHT "\t\t ��Ϸ���ڵ�״̬��  " + STATUS + "\n" NOR);
        //write(NOR + WHT "\t\t ��Ϸ�� PK ����:   ÿ��ÿ�첻���� " + MAX_KILL_PLAYER + " ��\n\n" NOR);
	   
	if (wizardp(me)) {
		check(objs,"����������");
		check(hearts,"����������");
		check_room(objs);
	}
	
        me->set_temp("scan_time", time());

        return 1;
}

string memory_expression(int m)
{
        float mem;

        mem = m;
        if( mem<1024 ) return m + "";
        if( mem<1024*1024 )

                return sprintf("%.2f K", (float)mem / 1024);
        return sprintf("%.3f M", (float)mem / (1024*1024));
}

int count_ppls()
{
        int count,i;
        string *dir, *ppls;

        seteuid(getuid());

        dir = get_dir(DATA_DIR + "login/");
        for(i=0; i<sizeof(dir); i++) {
        ppls = get_dir(DATA_DIR + "login/" + dir[i] + "/");
        count += sizeof(ppls);
        }
        return count;
}

string dotime()
{
        int t;
        string time;

        t = uptime();
	   time = CHINESE_D->chinese_period(t);
        return time;
}

int help() {

   write(@HELP
ָ���ʽ��mudinfo

���ָ�����ʾ�й���� Mud ��һЩϵͳ��Ѷ��

HELP
        );
         return 1;
}


