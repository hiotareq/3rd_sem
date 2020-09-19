#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <sys/types.h>                                                                                                                                                  
#include <grp.h>

int main(int argc, char*argv[]){
	int j, ngroups = 0;
	gid_t *groups;	
	struct passwd  *pw;
	struct group *gr;
	if (argc == 1){
	pw = getpwuid(getuid());
	getgrouplist(pw->pw_gecos, pw->pw_gid, groups, &ngroups);
	groups=malloc(ngroups * sizeof(gid_t));
	getgrouplist(pw->pw_gecos, pw->pw_gid, groups, &ngroups);
	printf("uid=%d(%s)%c",getuid(), (getpwuid(getuid())->pw_gecos),' ' );
	printf("gid=%d(%s)%c", getgid(),(getpwuid(getuid())->pw_gecos), ' ');
	printf("groups=");
	for (j = 0; j < ngroups; j++) {                                                                                                                                             printf("%d", groups[j]);                                                                                                                                                gr = getgrgid(groups[j]);                                                                                                                                               if (gr != NULL)                                                                                                                                                              printf("(%s)", gr->gr_name);                                                                                                                                       printf("\n");                                                                                                                                                       }
	}
	else{
		pw = getpwnam(argv[1]);
		getgrouplist(argv[1], pw->pw_gid, groups, &ngroups);
		groups = malloc(ngroups * sizeof(gid_t));
		getgrouplist(argv[1], pw->pw_gid, groups, &ngroups);
		printf("uid=%d(%s)%c", pw->pw_uid, argv[1], ' ');
		printf("gid=%d(%s)%c", pw->pw_gid, argv[1], ' ');
		printf("groups=");
		for ( j =0; j < ngroups; j++){
			printf("%d", groups[j]);
			gr = getgrgid(groups[j]);
			if ( gr != NULL)
				printf("(%s)", gr->gr_name);
			if ( j != (ngroups-1 ) ) 
				printf(",");
		}
		printf("\n");
	}
	return 0;
}

